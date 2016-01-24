using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace U_Ledge
{
    class LibFileFunction
    {
        public static StructPlayer getPlayerInfo( string name )
        {
            string filePath = Program.path + @"\players\" + name + @".up";
            StreamReader fileReading = File.OpenText(filePath);
            StructPlayer playerReading = new StructPlayer();

            playerReading.name = name;
            fileReading.ReadLine();
            playerReading.level = Convert.ToInt32(fileReading.ReadLine());
            fileReading.ReadLine();
            playerReading.hitPointMax = Convert.ToInt32(fileReading.ReadLine());
            fileReading.ReadLine();
            playerReading.attackPower = Convert.ToInt32(fileReading.ReadLine());
            return playerReading;
        }

    }
}
