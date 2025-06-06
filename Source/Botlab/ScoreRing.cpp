// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreRing.h"


// Sets default values
AScoreRing::AScoreRing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root=CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	StaticMesh=CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(Root);

	Box=CreateDefaultSubobject<UBoxComponent>("Box");
	Box->SetupAttachment(StaticMesh);

}

// Called when the game starts or when spawned
void AScoreRing::BeginPlay()
{
	Super::BeginPlay();

	DroneGI=Cast<UDroneGameInstance>(GetWorld()->GetGameInstance());
	
	Box->OnComponentBeginOverlap.AddDynamic(this,&AScoreRing::OnBoxOverlapBegin);
	
}

// Called every frame
void AScoreRing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AScoreRing::OnBoxOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsAvailable)
	{
		if (OtherActor && OtherActor->ActorHasTag("Drone"))
		{
			if (DroneGI)
			{
				DroneGI->Score++;
				IsAvailable=false;
				if (DroneGI->Score==DroneGI->MaxScore)
				{
					DroneGI->Win();
				}
			}
		}
	}
}

