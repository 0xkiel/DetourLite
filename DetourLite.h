#pragma once
#include <detours/detours.h>
#include <Windows.h>

template <typename fn>

bool  DetourThis(fn& orig, fn hook) {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)orig, hook);
	return DetourTransactionCommit() == SUCCESFULL;
}

template <typename fn>

bool DetourClean(fn& orig, fn hook) {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)orig, hook);
	return DetourTransactionCommit() == SUCCESFULL;
}

template <typename fn, typename RVA>

void DetourUnityFix(fn& orig, RVA rva) {
	orig = (fn)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + rva);
}