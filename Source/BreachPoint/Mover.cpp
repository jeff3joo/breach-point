// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();
	OwnerActorForMover = GetOwner();
	if (!OwnerActorForMover) return;

	StartLocation = OwnerActorForMover->GetActorLocation();
	EndLocation = StartLocation + Range;
	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!OwnerActorForMover) return;
	float Speed = Range.Length() / TimeToMove;
	FVector TargetLocation;
	if (ShouldMove) 
	{
		FVector CurrentLocation = OwnerActorForMover->GetActorLocation();
		TargetLocation = FMath::VInterpConstantTo(CurrentLocation, EndLocation, DeltaTime, Speed);
	} else {
		TargetLocation = StartLocation;
	}

	OwnerActorForMover->SetActorLocation(TargetLocation);
}

