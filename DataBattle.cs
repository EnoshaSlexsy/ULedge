using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace U_Ledge
{
    class DataBattle
    {
        public StructPlayer playerFirst = new StructPlayer();
        public StructPlayer playerSecond = new StructPlayer();
        public void playerRefresh()
        {
            playerFirst.hitPointCurrent = playerFirst.hitPointMax;
            playerSecond.hitPointCurrent = playerSecond.hitPointMax;
        }
    }
}
