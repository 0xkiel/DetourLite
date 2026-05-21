#pragma once
#include <detours/detours.h>
#include <Windows.h>


template <typename fn>

void  DetourThis(fn& orig, fn hook) {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)orig, hook);
	DetourTransactionCommit();
}

template <typename fn>

void DetourClean(fn& orig, fn hook) {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)orig, hook);
	DetourTransactionCommit();
}

template <typename fn, typename RVA>

void DetourUnityFix(fn& orig, RVA rva) {
	orig = (fn)((uintptr_t)GetModuleHandleA("GameAssembly.dll") + rva);
}

template <typename fn, typename RVA>

void DetourCallUnityFunc(fn& funcname, RVA rva ) {
	uintptr_t GameAssembly = (uintptr_t)GetModuleHandleA("GameAssembly.dll");
	funcname = (fn)(GameAssembly + rva);
}

