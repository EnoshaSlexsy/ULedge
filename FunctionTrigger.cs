using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace U_Ledge
{
    class FunctionTrigger
    {
        public string action( StructPlayer self, StructPlayer target, string actionName, string actionType, int actionPower)
        {
            string report;
            if (actionType == "heal")
            {
                report = self.name + " healed for " + actionPower.ToString() + "(" + actionName + ")";
                self.hitPointCurrent += actionPower;
                return report;
            }
            if (actionType == "damage")
            {
                report = self.name + " damaged " + target.name + " for " + actionPower.ToString() + "(" + actionName + ")";
                target.hitPointCurrent -= actionPower;
                return report;
            }
            if (actionType == "criticalPower")
            {
                self.criticalPower += actionPower;
            }
            if (actionType == "criticalChance")
            {
                self.criticalChance += actionPower;
            }
            if (actionType == "hitpointSet")
            {
                self.hitPointCurrent = actionPower;
            }
            return "";
        }
    }
}
