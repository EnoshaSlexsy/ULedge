using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.Diagnostics;

namespace U_Ledge
{
    public partial class formBattle : Form
    {
        DataBattle dataBattle = new DataBattle();

        public formBattle()
        {
            InitializeComponent();

            setPlayerName(Program.playerFirstName, Program.playerSecondName);
            dataBattle.playerFirst = LibFileFunction.getPlayerInfo(dataBattle.playerFirst.name);
            dataBattle.playerSecond = LibFileFunction.getPlayerInfo(dataBattle.playerSecond.name);
            dataBattle.playerRefresh();
            setFormInfo();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            btnPlayerSecondAttack.Visible = false;
        }
        public void setPlayerName( string nameFirst, string nameSecond)
        {
            dataBattle.playerFirst.name = nameFirst;
            dataBattle.playerSecond.name = nameSecond;
        }
        public void setFormInfo()
        {
            groupBoxFirst.Text = dataBattle.playerFirst.name;
            labelFirstHitPoint.Text = dataBattle.playerFirst.hitPointCurrent + "/" + dataBattle.playerFirst.hitPointMax;
            labelFirstAttack.Text = dataBattle.playerFirst.attackPower.ToString();

            groupBoxSecond.Text = dataBattle.playerSecond.name;
            labelSecondHitPoint.Text = dataBattle.playerSecond.hitPointCurrent + "/" + dataBattle.playerSecond.hitPointMax;
            labelSecondAttack.Text = dataBattle.playerSecond.attackPower.ToString();
        }

        private void btnPlayerFirstAttack_Click(object sender, EventArgs e)
        {
            textBoxBattleLog.Text = dataBattle.playerFirst.attack(dataBattle.playerSecond) + "\n" + textBoxBattleLog.Text;
            btnPlayerFirstAttack.Visible = false;
            btnPlayerSecondAttack.Visible = true;
            setFormInfo();
            isEnd();
        }

        private void btnPlayerSecondAttack_Click(object sender, EventArgs e)
        {
            textBoxBattleLog.Text = dataBattle.playerSecond.attack(dataBattle.playerFirst) + "\n" + textBoxBattleLog.Text;
            btnPlayerFirstAttack.Visible = true;
            btnPlayerSecondAttack.Visible = false;
            setFormInfo();
            isEnd();
        }
        private void isEnd()
        {
            if( dataBattle.playerFirst.hitPointCurrent < 1 || dataBattle.playerSecond.hitPointCurrent < 1)
            {
                if (dataBattle.playerFirst.hitPointCurrent >= dataBattle.playerSecond.hitPointCurrent)
                {
                    MessageBox.Show(dataBattle.playerFirst.name + " win!");
                }
                else
                {
                    MessageBox.Show(dataBattle.playerSecond.name + " win!");
                }
                Close();
            }

        }
    }
}
