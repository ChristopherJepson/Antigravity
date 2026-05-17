#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AntigravityTestActor.generated.h"

UCLASS()
class SPACESURVIVORII_API AAntigravityTestActor : public AActor
{
    GENERATED_BODY()
    
public:    
    AAntigravityTestActor();

protected:
    virtual void BeginPlay() override;

public:    
    void UpdateOrbit(float DeltaTime);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<class UStaticMeshComponent> StaticMeshComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<class USphereComponent> SphereComponent;
};
