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


	UPROPERTY(EditAnywhere, Category = Firing) float MaxDegreesPerSecond = 5;
	UPROPERTY(EditAnywhere, Category = Firing) float MaxElevation = 40;
	UPROPERTY(EditAnywhere, Category = Firing) float MinElevation = 0;

};
