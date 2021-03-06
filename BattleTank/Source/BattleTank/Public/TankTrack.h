// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:

	UFUNCTION(BlueprintCallable, Category = Setup) void SetThrottle(float throttle);
	UPROPERTY(EditDefaultsOnly) float TrackMaxDrivingForce = 80000; // max force per track in newtons
};
