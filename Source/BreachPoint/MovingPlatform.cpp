// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values for this component's properties
UMovingPlatform::UMovingPlatform()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	OwnerActor = GetOwner();
	if (!OwnerActor) return;

	StartLocation = OwnerActor->GetActorLocation();		
}


// Called every frame
void UMovingPlatform::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!OwnerActor) return;
	Move(DeltaTime);
	if (ShouldRotate) Rotate(DeltaTime);

}

// Moving Logic
void UMovingPlatform::Move(float DeltaTime)
{
	if (ShouldMove)
	{
		EndLocation = StartLocation + Range;
	}
	else {
		EndLocation = StartLocation;
	}
	
	float Speed = Range.Length() / TimeToMove;
	FVector TargetLocation;
	FVector CurrentLocation = OwnerActor->GetActorLocation();
	TargetLocation = FMath::VInterpConstantTo(CurrentLocation, EndLocation, DeltaTime, Speed);

	OwnerActor->SetActorLocation(TargetLocation);
}

//Rotating Logic
void UMovingPlatform::Rotate(float DeltaTime)
{
	FRotator RotationToAdd = RotationVelocity * DeltaTime;
	OwnerActor->AddActorLocalRotation(RotationToAdd);

}

bool UMovingPlatform::GetShouldMove()
{
	return ShouldMove;
}

void UMovingPlatform::SetShouldMove(bool NewShouldMove)
{
	ShouldMove = NewShouldMove;
}

bool UMovingPlatform::GetShouldRotate()
{
	return ShouldRotate;
}

void UMovingPlatform::SetShouldRotate(bool NewShouldRotate)
{
	ShouldRotate = NewShouldRotate;
}