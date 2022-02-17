#pragma once

class RODUtils
{
public:
	template<typename T>
	static T* GetRODPlayerComponent (AActor* PlayerPawn)
	{
		if (!PlayerPawn) return nullptr;

		const auto Component = PlayerPawn->GetComponentByClass(T::StaticClass());
		return Cast<T>(Component);
	}
};