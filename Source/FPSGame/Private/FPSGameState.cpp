// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSGameState.h"
#include "FPSPlayerController.h"


void AFPSGameState::MulticastOnMissionComplete_Implementation(APawn* InstigatorPawn, bool bMissionSuccess)
{
	//	get all pawns that exist on the level
//	for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; It++)
//	{
//		APawn* Pawn = It->Get();
//
		//	and ...
//		if (Pawn && Pawn->IsLocallyControlled())
//		{
//			Pawn->DisableInput(nullptr);
//		}
//	}

	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
	{
		AFPSPlayerController* PC = Cast<AFPSPlayerController>(It->Get());
		if (PC && PC->IsLocalController())
		{
			PC->OnMissionComplete(InstigatorPawn, bMissionSuccess);

			//	Replaces previous loop "for", that disables input
			APawn* Pawn = PC->GetPawn();
			if (Pawn)
			{
				Pawn->DisableInput(PC);
			}	

		}
	}
}


