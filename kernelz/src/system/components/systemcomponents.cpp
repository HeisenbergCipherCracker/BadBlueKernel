#include <system/components/systemcomponent.h>

using namespace HeisenOs;
using namespace HeisenOs::common;
using namespace HeisenOs::system;

SystemComponent::SystemComponent(char* name, char* description)
{
    this->Name = name;
    this->Description = description;
}

char* SystemComponent::GetComponentName()
{
    return this->Name;
}
char* SystemComponent::GetComponentDescription()
{
    return this->Description;
}