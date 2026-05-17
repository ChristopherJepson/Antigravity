#include "AntigravityTestActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "SpaceSurvivorII.h"

AAntigravityTestActor::AAntigravityTestActor()
{
    PrimaryActorTick.bCanEverTick = false;

    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    RootComponent = SphereComponent;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    StaticMeshComponent->SetupAttachment(RootComponent);
}

void AAntigravityTestActor::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogSpaceSurvivor, Log, TEXT("AntigravityTestActor online!"));
}

void AAntigravityTestActor::UpdateOrbit(float DeltaTime)
{
    FVector CurrentLocation = GetActorLocation();
    FVector OrbitDisplacement = FVector(100.0, 0.0, 0.0) * DeltaTime;
    SetActorLocation(CurrentLocation + OrbitDisplacement);
}
