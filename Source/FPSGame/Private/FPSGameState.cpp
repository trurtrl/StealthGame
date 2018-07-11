// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSGameState.h"



void AFPSGameState::MulticastOnMissionComplete_Implementation(APawn* InstigatorPawn, bool bMissionSuccess)
{
	//	get all pawns that exist on the level
	for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; It++)
	{
		APawn* Pawn = It->Get();

		//	and ...
		if (Pawn && Pawn->IsLocallyControlled())
		{
			Pawn->DisableInput(nullptr);
		}
	}
}


