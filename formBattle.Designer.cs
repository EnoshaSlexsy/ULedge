namespace U_Ledge
{
    partial class formBattle
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBoxFirst = new System.Windows.Forms.GroupBox();
            this.labelFirstAttack = new System.Windows.Forms.Label();
            this.labelFirstHitPoint = new System.Windows.Forms.Label();
            this.groupBoxSecond = new System.Windows.Forms.GroupBox();
            this.labelSecondAttack = new System.Windows.Forms.Label();
            this.labelSecondHitPoint = new System.Windows.Forms.Label();
            this.btnPlayerFirstAttack = new System.Windows.Forms.Button();
            this.btnPlayerSecondAttack = new System.Windows.Forms.Button();
            this.textBoxBattleLog = new System.Windows.Forms.TextBox();
            this.groupBoxFirst.SuspendLayout();
            this.groupBoxSecond.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBoxFirst
            // 
            this.groupBoxFirst.Controls.Add(this.labelFirstAttack);
            this.groupBoxFirst.Controls.Add(this.labelFirstHitPoint);
            this.groupBoxFirst.Font = new System.Drawing.Font("Ubuntu Mono", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.groupBoxFirst.Location = new System.Drawing.Point(52, 27);
            this.groupBoxFirst.Name = "groupBoxFirst";
            this.groupBoxFirst.Size = new System.Drawing.Size(200, 100);
            this.groupBoxFirst.TabIndex = 2;
            this.groupBoxFirst.TabStop = false;
            this.groupBoxFirst.Text = "First Player";
            // 
            // labelFirstAttack
            // 
            this.labelFirstAttack.AutoSize = true;
            this.labelFirstAttack.Cursor = System.Windows.Forms.Cursors.Default;
            this.labelFirstAttack.Location = new System.Drawing.Point(46, 58);
            this.labelFirstAttack.Name = "labelFirstAttack";
            this.labelFirstAttack.Size = new System.Drawing.Size(103, 15);
            this.labelFirstAttack.TabIndex = 3;
            this.labelFirstAttack.Text = "labelFirstAttack";
            // 
            // labelFirstHitPoint
            // 
            this.labelFirstHitPoint.AutoSize = true;
            this.labelFirstHitPoint.Cursor = System.Windows.Forms.Cursors.Default;
            this.labelFirstHitPoint.Location = new System.Drawing.Point(46, 42);
            this.labelFirstHitPoint.Name = "labelFirstHitPoint";
            this.labelFirstHitPoint.Size = new System.Drawing.Size(115, 15);
            this.labelFirstHitPoint.TabIndex = 1;
            this.labelFirstHitPoint.Text = "labelFirstHitPoint";
            // 
            // groupBoxSecond
            // 
            this.groupBoxSecond.Controls.Add(this.labelSecondAttack);
            this.groupBoxSecond.Controls.Add(this.labelSecondHitPoint);
            this.groupBoxSecond.Font = new System.Drawing.Font("Ubuntu Mono", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.groupBoxSecond.Location = new System.Drawing.Point(346, 27);
            this.groupBoxSecond.Name = "groupBoxSecond";
            this.groupBoxSecond.Size = new System.Drawing.Size(200, 100);
            this.groupBoxSecond.TabIndex = 4;
            this.groupBoxSecond.TabStop = false;
            this.groupBoxSecond.Text = "Second Player";
            // 
            // labelSecondAttack
            // 
            this.labelSecondAttack.AutoSize = true;
            this.labelSecondAttack.Cursor = System.Windows.Forms.Cursors.Default;
            this.labelSecondAttack.Location = new System.Drawing.Point(46, 58);
            this.labelSecondAttack.Name = "labelSecondAttack";
            this.labelSecondAttack.Size = new System.Drawing.Size(109, 15);
            this.labelSecondAttack.TabIndex = 3;
            this.labelSecondAttack.Text = "labelSecondAttack";
            // 
            // labelSecondHitPoint
            // 
            this.labelSecondHitPoint.AutoSize = true;
            this.labelSecondHitPoint.Cursor = System.Windows.Forms.Cursors.Default;
            this.labelSecondHitPoint.Location = new System.Drawing.Point(46, 42);
            this.labelSecondHitPoint.Name = "labelSecondHitPoint";
            this.labelSecondHitPoint.Size = new System.Drawing.Size(121, 15);
            this.labelSecondHitPoint.TabIndex = 1;
            this.labelSecondHitPoint.Text = "labelSecondHitPoint";
            // 
            // btnPlayerFirstAttack
            // 
            this.btnPlayerFirstAttack.Location = new System.Drawing.Point(61, 151);
            this.btnPlayerFirstAttack.Name = "btnPlayerFirstAttack";
            this.btnPlayerFirstAttack.Size = new System.Drawing.Size(50, 41);
            this.btnPlayerFirstAttack.TabIndex = 6;
            this.btnPlayerFirstAttack.Text = "Attack";
            this.btnPlayerFirstAttack.UseVisualStyleBackColor = true;
            this.btnPlayerFirstAttack.Click += new System.EventHandler(this.btnPlayerFirstAttack_Click);
            // 
            // btnPlayerSecondAttack
            // 
            this.btnPlayerSecondAttack.Location = new System.Drawing.Point(493, 151);
            this.btnPlayerSecondAttack.Name = "btnPlayerSecondAttack";
            this.btnPlayerSecondAttack.Size = new System.Drawing.Size(53, 41);
            this.btnPlayerSecondAttack.TabIndex = 7;
            this.btnPlayerSecondAttack.Text = "Attack";
            this.btnPlayerSecondAttack.UseVisualStyleBackColor = true;
            this.btnPlayerSecondAttack.Click += new System.EventHandler(this.btnPlayerSecondAttack_Click);
            // 
            // textBoxBattleLog
            // 
            this.textBoxBattleLog.Location = new System.Drawing.Point(197, 183);
            this.textBoxBattleLog.MinimumSize = new System.Drawing.Size(200, 90);
            this.textBoxBattleLog.Multiline = true;
            this.textBoxBattleLog.Name = "textBoxBattleLog";
            this.textBoxBattleLog.ReadOnly = true;
            this.textBoxBattleLog.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxBattleLog.Size = new System.Drawing.Size(200, 90);
            this.textBoxBattleLog.TabIndex = 8;
            // 
            // formBattle
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(617, 301);
            this.Controls.Add(this.textBoxBattleLog);
            this.Controls.Add(this.btnPlayerSecondAttack);
            this.Controls.Add(this.btnPlayerFirstAttack);
            this.Controls.Add(this.groupBoxSecond);
            this.Controls.Add(this.groupBoxFirst);
            this.Name = "formBattle";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBoxFirst.ResumeLayout(false);
            this.groupBoxFirst.PerformLayout();
            this.groupBoxSecond.ResumeLayout(false);
            this.groupBoxSecond.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.GroupBox groupBoxFirst;
        private System.Windows.Forms.Label labelFirstAttack;
        private System.Windows.Forms.Label labelFirstHitPoint;
        private System.Windows.Forms.GroupBox groupBoxSecond;
        private System.Windows.Forms.Label labelSecondAttack;
        private System.Windows.Forms.Label labelSecondHitPoint;
        private System.Windows.Forms.Button btnPlayerFirstAttack;
        private System.Windows.Forms.Button btnPlayerSecondAttack;
        private System.Windows.Forms.TextBox textBoxBattleLog;
    }
}

