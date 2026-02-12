// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::Shoot(float Range, float Damage, int MagazineCapacity)
{
	if (CurrentBullets <= 0) {
		//await 
		Reload(MagazineCapacity);
	}
	if (OwnerController)
	{
		FVector ViewPointLocation;
		FRotator ViewPointRotation;
		OwnerController->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);

		FVector HitRangeEnd = ViewPointLocation + ViewPointRotation.Vector() * Range;

		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(GetOwner());
		bool IsHit = GetWorld()->LineTraceSingleByChannel(HitResult, ViewPointLocation, HitRangeEnd, ECC_GameTraceChannel1, Params);
		if (IsHit)
		{
			AActor* HitActor = HitResult.GetActor();
			if (HitActor)
			{
				DrawDebugSphere(GetWorld(),HitResult.ImpactPoint,20.0f,8,FColor::Red);
			}
		}
	}
}

void AGun::Reload(int MagazineCapacity)
{
	//Await Play Animation
	CurrentBullets = MagazineCapacity;
}

