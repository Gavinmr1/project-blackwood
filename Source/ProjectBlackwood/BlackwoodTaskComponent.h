#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BlackwoodTaskDefinition.h"
#include "BlackwoodTaskComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTaskUpdated);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTBLACKWOOD_API UBlackwoodTaskComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UBlackwoodTaskComponent();

    UFUNCTION(BlueprintCallable, Category = "Blackwood|Task")
    void SetActiveTask(UBlackwoodTaskDefinition* Task);

    UFUNCTION(BlueprintCallable, Category = "Blackwood|Task")
    void AddProgress(int32 Amount);

    UFUNCTION(BlueprintPure, Category = "Blackwood|Task")
    bool IsTaskComplete() const;

    UFUNCTION(BlueprintPure, Category = "Blackwood|Task")
    int32 GetCurrentProgress() const;

    UFUNCTION(BlueprintPure, Category = "Blackwood|Task")
    UBlackwoodTaskDefinition* GetActiveTask() const;

    UPROPERTY(BlueprintAssignable, Category = "Blackwood|Task")
    FOnTaskUpdated OnTaskUpdated;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Blackwood|Task", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UBlackwoodTaskDefinition> ActiveTask = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Blackwood|Task", meta = (AllowPrivateAccess = "true"))
    int32 CurrentProgress = 0;
};