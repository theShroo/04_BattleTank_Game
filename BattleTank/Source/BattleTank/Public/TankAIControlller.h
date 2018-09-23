// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TankAIControlller.generated.h"

/**
 * 
 */
class ATank;

UCLASS()
class BATTLETANK_API ATankAIControlller : public AAIController
{
	GENERATED_BODY()
public:


	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	
};
