// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class SPD_SPEL1_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Controls forward and backward movement (Rufus)
	void FrontBackMove(float AxisValue);
	
	// Controls right and left movement (Rufus)
	void RightLeftMove(float AxisValue);

	// Controls weapon swapping (Rufus)
	void SwapWeapon();

	// Controls weapon being fired, triggers 'PullTrigger()' in 'Weapon.h'
	void Shoot();

	// Function and bool is required in order to determine when the player stops shooting continuously (Rufus)
	void CancelShoot();
	bool SprayShooting = true;
	
	// Required for 'Shoot()'
	UPROPERTY()
	class AWeapon* TriggerWeapon;
	
	//AActor should preferably be our own 'WeaponClass' instead (Rufus)
	//Due to how TSubclass functions AActors cannot be pointers, this is solved in .cpp file vie use of references
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weaponry", meta=(AllowPrivateAccess="True"))
	TArray<TSubclassOf<class AWeapon>> InitialWeaponArray;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weaponry", meta=(AllowPrivateAccess="True"))
	TArray<class AWeapon*> CurrentWeaponArray;

};
