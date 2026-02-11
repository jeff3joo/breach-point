// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Math/Vector.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/Actor.h"

#include "MovingPlatform.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BREACHPOINT_API UMovingPlatform : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovingPlatform();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	//UPROPERTIES----------------------------------------
	UPROPERTY(EditAnywhere)
	FVector Range;

	UPROPERTY(EditAnywhere)
	FRotator RotationVelocity;

	UPROPERTY(EditAnywhere)
	float TimeToMove = 4.0f;

	UPROPERTY(EditAnywhere)
	bool ShouldMove = false;

	UPROPERTY(EditAnywhere)
	bool ShouldRotate = false;
	
	//FUNCTIONS-------------------------------------------
	void Move(float DeltaTime);
	void Rotate(float DeltaTime);
	
	//GET,SET
	bool GetShouldMove();
	void SetShouldMove(bool NewShouldMove);
	bool GetShouldRotate();
	void SetShouldRotate(bool NewShouldRotate);

	//Vars------------------------------------------------
	AActor* OwnerActor;
	FVector StartLocation;
	FVector EndLocation;
};
