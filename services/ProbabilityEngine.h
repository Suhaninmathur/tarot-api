#ifndef PROB_ENGINE_H
#define PROB_ENGINE_H

#include <string>
using namespace std;

class ProbabilityEngine
{

public:

static string analyzeEnergy(int energy)
{

if(energy >= 13)
return "A powerful energetic alignment suggests strong forward momentum.";

else if(energy >= 9)
return "Balanced forces indicate a period of stable progress.";

else
return "Lower energetic alignment suggests reflection and patience.";

}

};

#endif