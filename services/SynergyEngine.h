#pragma once
#include <string>
#include "../models/Card.h"   // in same services/ directory

class SynergyEngine {
public:
    // FIX: was accessing card.name directly, but name is private in Card.
    //      Use the public getName() accessor instead.
    static std::string getSynergy(const Card& past,
                                   const Card& present,
                                   const Card& future) {

        const std::string& p  = past.getName();
        const std::string& pr = present.getName();
        const std::string& f  = future.getName();

        if (p == "The Fool" && pr == "The High Priestess")
            return "Curiosity guided by intuition opens doors to hidden truths and unexpected opportunities.";
        if (pr == "The High Priestess" && f == "The Empress")
            return "Insights from introspection lead to creative growth and abundant outcomes.";
        if (p == "The Magician" && f == "The Star")
            return "Manifestation of your skills aligns with hope and inspiration.";
        if (p == "The Empress" && f == "The Emperor")
            return "Nurturing creativity is ready to be given lasting structure and form.";
        if (p == "The Chariot" && pr == "Strength")
            return "Hard-won momentum is deepening into patient, unshakeable inner power.";
        if (pr == "The Hermit" && f == "The Star")
            return "The wisdom gathered in solitude now shines outward as genuine, healing hope.";
        if (p == "The Lovers" && f == "The Chariot")
            return "A choice made from the heart now propels you into focused, decisive forward movement.";

        return "The combination encourages awareness, patience, and thoughtful decision-making.";
    }
};
