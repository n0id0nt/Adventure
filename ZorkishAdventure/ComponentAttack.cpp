#include "ComponentAttack.h"
#include "Entity.h"
#include "ComponentHealth.h"
#include "ComponentItem.h"
#include "ComponentHasInventory.h"

ComponentAttack::ComponentAttack(Entity* parent) : Component(parent)
{
}

ComponentAttack::~ComponentAttack()
{
}

std::string ComponentAttack::Look()
{
    return "\n - Can Attack";
}

std::string ComponentAttack::Attack(ComponentAttack* target, ComponentDamage* damage, bool& isAlive)
{
    ComponentHealth* health = target->GetParent()->GetComponent<ComponentHealth>("health");
    health->Damage(damage->GetDamage());

    std::string string = target->GetParent()->GetName() + " was attacked with " + damage->GetParent()->GetName() + " dealing " + std::to_string(damage->GetDamage()) + " damage";

    // check if target is dead
    if (health->GetHealth() > 0)
    {
        isAlive = true;
        string += "\n" + target->GetParent()->GetName() + "'s health is now " + std::to_string(health->GetHealth()) + "hp";
    }
    else
    {
        isAlive = false;
        string += "\n" + target->Die();
    }

    return string;
}

std::string ComponentAttack::Die()
{
    std::string string = l_parent->GetName() + "'s health has reached 0 and has died dropping:";
    // drop the inventory
    for (auto& item : l_parent->GetChildren())
    {
        if (item.second->HasComponent("item"))
        {
            string += "\n\t - " + item.first;
            item.second->GetComponent<ComponentItem>("item")->MoveItem(l_parent->GetParent()->GetComponent<ComponentHasInventory>("inventory"));
        }
    }
    // destroy self
    l_parent->GetParent()->DeleteChild(l_parent->GetName());

    return string;
}
