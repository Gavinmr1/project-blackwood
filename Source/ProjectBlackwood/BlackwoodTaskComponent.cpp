#include "BlackwoodTaskComponent.h"

UBlackwoodTaskComponent::UBlackwoodTaskComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UBlackwoodTaskComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UBlackwoodTaskComponent::SetActiveTask(UBlackwoodTaskDefinition* Task)
{
    ActiveTask = Task;
    CurrentProgress = 0;
    OnTaskUpdated.Broadcast();
}

void UBlackwoodTaskComponent::AddProgress(int32 Amount)
{
    if (!ActiveTask || Amount <= 0 || IsTaskComplete())
    {
        return;
    }

    CurrentProgress = FMath::Clamp(
        CurrentProgress + Amount,
        0,
        ActiveTask->TargetProgress
    );

    UE_LOG(LogTemp, Warning, TEXT("Task Progress: %d / %d"),
        CurrentProgress,
        ActiveTask ? ActiveTask->TargetProgress : 0);

    OnTaskUpdated.Broadcast();
}

bool UBlackwoodTaskComponent::IsTaskComplete() const
{
    return ActiveTask && CurrentProgress >= ActiveTask->TargetProgress;
}

int32 UBlackwoodTaskComponent::GetCurrentProgress() const
{
    return CurrentProgress;

}

UBlackwoodTaskDefinition* UBlackwoodTaskComponent::GetActiveTask() const
{
    return ActiveTask;
}