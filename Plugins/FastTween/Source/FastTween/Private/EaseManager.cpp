// Fill out your copyright notice in the Description page of Project Settings.


#include "EaseManager.h"
#include <cmath>
#include "Tween/Tween.h"

float FEaseManager::pi = 3.1415926f;
float FEaseManager::piOverTwo = 1.5707964f;
float FEaseManager::twoPi = 6.2831855f;

float FEaseManager::Evaluate(UTween* t, float time, float duration, float overshootOrAmplitude, float period)
{
	return Evaluate(t->EaseType, time, duration, overshootOrAmplitude, period, t->bIsReversed);
}

float FEaseManager::Evaluate(EEaseType easeType, float time, float duration, float overshootOrAmplitude, float period, bool isReversed)
{
    float alpha;
	float s;
    
	switch (easeType)
    {
        case EEaseType::Linear:
            alpha = time / duration;
            break;
        case EEaseType::InSine:
            alpha = -std::cos(time / duration * piOverTwo) + 1.0f;
            break;
        case EEaseType::OutSine:
            alpha = std::sin(time / duration * piOverTwo);
            break;
        case EEaseType::InOutSine:
            alpha = -0.5f * (std::cos(pi * time / duration) - 1.0f);
	        break;
        case EEaseType::InQuad:
            alpha = (time /= duration) * time;
	        break;
        case EEaseType::OutQuad:
            alpha = -(time /= duration) * (time - 2.0f);
	        break;
        case EEaseType::InOutQuad:
            time /= duration * 0.5f;
            alpha = (time < 1.0f) ? 0.5f * time * time : -0.5f * (--time * (time - 2.0f) - 1.0f);
	        break;
        case EEaseType::InCubic:
            alpha = (time /= duration) * time * time;
	        break;
        case EEaseType::OutCubic:
            time = time / duration - 1.0f;
            alpha = time * time * time + 1.0f;
	        break;
        case EEaseType::InOutCubic:
            time /= duration * 0.5f;
            alpha = (time < 1.0f) ? 0.5f * time * time * time : 0.5f * ((time -= 2.0f) * time * time + 2.0f);
	        break;
        case EEaseType::InQuart:
            alpha = (time /= duration) * time * time * time;
	        break;
        case EEaseType::OutQuart:
            time = time / duration - 1.0f;
            alpha = -(time * time * time * time - 1.0f);
	        break;
        case EEaseType::InOutQuart:
            time /= duration * 0.5f;
            alpha = (time < 1.0f) ? 0.5f * time * time * time * time : -0.5f * ((time -= 2.0f) * time * time * time - 2.0f);
	        break;
        case EEaseType::InQuint:
            alpha = (time /= duration) * time * time * time * time;
	        break;
        case EEaseType::OutQuint:
            time = time / duration - 1.0f;
            alpha = time * time * time * time * time + 1.0f;
	        break;
        case EEaseType::InOutQuint:
            time /= duration * 0.5f;
            alpha = (time < 1.0f) ? 0.5f * time * time * time * time * time : 0.5f * ((time -= 2.0f) * time * time * time * time + 2.0f);
	        break;
	    case EEaseType::InExpo:
            alpha = (time == 0.0f) ? 0.0f : std::pow(2.0f, 10.0f * (time / duration - 1.0f));
	        break;
        case EEaseType::OutExpo:
            alpha = (time == duration) ? 1.0f : -std::pow(2.0f, -10.0f * time / duration) + 1.0f;
	        break;
        case EEaseType::InOutExpo:
            if (time == 0.0f) alpha = 0.0f;
            if (time == duration) alpha = 1.0f;
            time /= duration * 0.5f;
            alpha = (time < 1.0f) ? 0.5f * std::pow(2.0f, 10.0f * (time - 1.0f)) : 0.5f * (-std::pow(2.0f, -10.0f * --time) + 2.0f);
	        break;
        case EEaseType::InCirc:
            alpha = -(std::sqrt(1.0f - (time /= duration) * time) - 1.0f);
	        break;
        case EEaseType::OutCirc:
            time = time / duration - 1.0f;
            alpha = std::sqrt(1.0f - time * time);
	        break;
        case EEaseType::InOutCirc:
            time /= duration * 0.5f;
            alpha = (time < 1.0f) ? -0.5f * (std::sqrt(1.0f - time * time) - 1.0f) : 0.5f * (std::sqrt(1.0f - (time -= 2.0f) * time) + 1.0f);
			break;
	    case EEaseType::InElastic: 
            if (time == 0.0f) 
            {
            	alpha = 0.0f;
            	break;
            }
            if ((time /= duration) == 1.0f) 
			{
            	alpha = 1.0f;
            	break;
        	}
            if (period == 0.0f) period = duration * 0.3f;
            s = (overshootOrAmplitude < 1.0f) ? period / 4.0f : period / (2.0f * pi) * std::asin(1.0f / overshootOrAmplitude);
            alpha = -(overshootOrAmplitude * std::pow(2.0f, 10.0f * --time) * std::sin((time * duration - s) * (2.0f * pi) / period));
			break;
        case EEaseType::OutElastic:
        	if (time == 0.0f) 
        	{
        		alpha = 0.0f;
        		break;
        	}
			if ((time /= duration) == 1.0f) 
			{
				alpha = 1.0f;
				break;
			}
            if (period == 0.0f) period = duration * 0.3f;
            s = (overshootOrAmplitude < 1.0f) ? period / 4.0f : period / (2.0f * pi) * std::asin(1.0f / overshootOrAmplitude);
            alpha = overshootOrAmplitude * std::pow(2.0f, -10.0f * time) * std::sin((time * duration - s) * (2.0f * pi) / period) + 1.0f;
			break;

		default:
			alpha = 0.0f;
			break;
    }

	UE_LOG(FastTween, Warning, TEXT("Alpha : %f"), alpha);
    return isReversed == true ? 1 - alpha : alpha;
}
