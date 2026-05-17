#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

void UMainMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (IsValid(Btn_Quit))
    {
        Btn_Quit->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitButtonClicked);
    }
}

void UMainMenuWidget::OnQuitButtonClicked()
{
    if (GetWorld())
    {
        UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
    }
}
