# DetourLite
just another garbage simple detour wrapper for c++ for simplicity

## Installation

### requirements 

* Windows 10 || Windows 11 sdk 
* installed detour via vcpkg or change the header to manual include detour

### Example using the wrapper
```C++

RVA: 0x5A74E70
void VeryRealMoneyFunction(float MoneyGive, int Amount)
// This will be our example function and it has 2 params being how much money to give that is a float number
// and the last param is amount which we will assume how many times to give such amount 


typedef void(*VeryRealMoneyFunction)(float,int);
// we will use a typedef to remake the func
// it will be a void cuz the func is a void in the original function && the params will be float and int as the original func is

VeryRealMoneyFunction orig_VeryRealMoneyFunction = nullptr;
// we will now make this temporarily 2nd naming can be whatever you want however it is suggested you add orig_(function name here)

void h_VeryRealMoneyFunction(float MoneyGive, int Amount) {
	MoneyGive = 110.0;
  Amount = 5;

	orig_VeryRealMoneyFunction(MoneyGive, Amount);
}

//this function that we made will be a void as the original function is a void and it MUST match
// this function copies the same params as the original function
// inside of the function is where you put the values u want ms detours to hook and replace with
// you now MUST type in your orig func from earlier or else it wont work with the param names NOT the datatype of params

DetourUnityFix(orig_VeryRealMoneyFunction, 0x5A74E70);
//DetourUnityFix is situational and may or may not be needed idk what you ur using detours for
// however in this example we will use this func to fix our temp nullptr as the name implies(it also also grabs unity)

DetourThis(orig_VeryRealMoneyFunction, h_VeryRealMoneyFunction);
// now we can finish off with our last func to tell detour to now use what we just did in our example into our real hook
//if you followed this tutorial correctly and this was real once the hook runs and the game calls the function VeryRealMoneyFunction
// boom profit u would now get 550 moneys

DetourClean(orig_VeryRealMoneyFunction, h_VeryRealMoneyFunction);
// now we will use this function to clean up the hooks and removes the hooks
// DetourCLean is optional tho is subjective i personally dont use it however the function is there for those who need it
// DetourClean also takes the same params as DetourThis so feel free to copy paste DetourThis just change This to Clean


```
