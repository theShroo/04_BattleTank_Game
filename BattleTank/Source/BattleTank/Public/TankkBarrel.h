// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankkBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankkBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	//-1 is max down, 1 is max up
	void Elevate(float RelativeSpeed);


	UPROPERTY(EditDefaultsOnly, Category = Firing) float MaxDegreesPerSecond = 10;
	UPROPERTY(EditDefaultsOnly, Category = Firing) float MaxElevation = 40;
	UPROPERTY(EditDefaultsOnly, Category = Firing) float MinElevation = 0;

};
