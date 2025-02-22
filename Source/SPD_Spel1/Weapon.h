// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class SPD_SPEL1_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	FVector Location;
	UPROPERTY()
	FRotator Rotation;
	UPROPERTY()
	FVector End;
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Is a shoot function, triggered from PlayerCharacter.cpp under Shoot function as well as CancelShoot under it (Rufus)
	void PullTrigger(bool SprayShooting);

	// The default way of shooting if no projectile is specified in blueprints (Rufus)
	// Public access may be redundant (Rufus)
	void ShootWithoutProjectile();

	// Shooting method called if a projectile is specified in blueprints (Rufus)
	// Public access may be redundant (Rufus)
	void ShootProjectile();
	
private:
	
	// Max range is applicable only when no projectile is found, in case of projectile max range should be regulated with physics (Rufus)
	UPROPERTY(EditAnywhere, Category="Weaponry")
	float MaxShootingRange = 1000;

	// If no projectile is set in BlueprintEditor the fallback is direct shots
	UPROPERTY(EditAnywhere, Category="Weaponry")
	TSubclassOf<class AProjectile> Projectile;

	FTimerHandle SprayShootingTimer;


};
