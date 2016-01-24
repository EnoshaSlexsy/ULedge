using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace U_Ledge
{
    static class Program
    {
        public static string path = @"..\..\source\";
        public static string playerFirstName;
        public static string playerSecondName;
        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new formInputPlayer());
            Application.Run(new formBattle());
        }
    }
}
