// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"




void UTankTrack::SetThrottle(float throttle) {
		FVector ForceApplied = GetForwardVector() * throttle * TrackMaxDrivingForce;
		auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
		tankRoot->AddForceAtLocation(ForceApplied, GetComponentLocation());
}