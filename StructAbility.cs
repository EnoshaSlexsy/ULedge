using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace U_Ledge
{
    class StructAbility
    {
        const int ABILITY_PARAMETER_MAX = 3;
        const int PARAMETER_COUNT_MAX = 3;
        const int ABILITY_LEVEL_MAX = 10;

        List<List<int>> power = new List<List<int>>();
        List<string>    triggerType = new List<string>();
        string          actionType;
        string          description;
        string          name;
        int             levelMax;
        int             parameterCount;
	    int             countdownMax;
    }
}
