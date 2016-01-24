using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace U_Ledge
{
    class StructPlayer
    {
        public string name;
        public int level;
        public int hitPointMax;
        public int attackPower;
        public int hitPointCurrent;
        public int criticalChance, criticalPower;
        List<int> abilityLevel;
        List<int> abilityCountdown;

        public string gettingDamage(StructPlayer opponent, int damage)
        {
            hitPointCurrent -= damage;
            return opponent.name + " damaged " + this.name + " for " + damage.ToString() + " \n ";
        }
        public string attack( StructPlayer target)
        {
            return target.gettingDamage( this, attackPower);
        }
        public void setBot()
        {
            name = "Bot";
            level = 1;
            attackPower = 10;
            hitPointMax = 100;
            criticalChance = 0;
            criticalPower = 0;
        }
    }
}
