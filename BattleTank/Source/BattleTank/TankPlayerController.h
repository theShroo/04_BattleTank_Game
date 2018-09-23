// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void AimTowardCrosshair();
	bool GetSightRayHitLocation(FVector &OUTHitLocation)const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection, FVector& Position) const;

private:
	UPROPERTY(EditAnywhere)float CrosshairXPosition = 0.5f;
	UPROPERTY(EditAnywhere)float CrosshairYPosition = 1/3.0f;
};
