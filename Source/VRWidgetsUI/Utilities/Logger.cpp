#include "Logger.h"

void Logger::Log(FString Text)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Text);
}
