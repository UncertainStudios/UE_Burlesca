// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DIHelpersClasses.generated.h"

class UDependencyContainer;

UCLASS()
class BURLESCA_API UBindInfo : public UObject
{
	GENERATED_BODY()

public:
	UBindInfo();
	
	UClass* FromBindClass;
	UClass* ToBindClass;

	UPROPERTY()
	UDependencyContainer* Container;
};



UCLASS()
class BURLESCA_API UFromBinder : public UObject
{
	GENERATED_BODY()

public:
	UFromBinder();

	/**
	* @brief Don't use this function.
	* It`s internal framework function.
	* Use From...() instead.
	*/
	template <typename T>
	void Init(UDependencyContainer* Container)
	{
		BindInfo = NewObject<UBindInfo>(this);
		BindInfo->FromBindClass = T::StaticClass();
		BindInfo->Container = Container;
	}
	
	UToBinder* FromNew() const;

	void FromInstance(UObject* Object) const;

private:
	UPROPERTY()
	UBindInfo* BindInfo;
	
};



UCLASS()
class BURLESCA_API UToBinder : public UObject
{
	GENERATED_BODY()

public:
	UToBinder();
	void Init(UBindInfo* bindInfo);
	
	/**
 * @brief Use this function to select object of what class must be created.
 * If you binding interface then your object class must implement this interface.
 *
 * @tparam T Created Object Class
 */
	template <typename T>
	void To();
	

private:

	UPROPERTY()
	UBindInfo* BindInfo;
};
