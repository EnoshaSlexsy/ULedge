namespace U_Ledge
{
    partial class formInputPlayer
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnStart = new System.Windows.Forms.Button();
            this.textBoxPlayerFirst = new System.Windows.Forms.TextBox();
            this.textBoxPlayerSecond = new System.Windows.Forms.TextBox();
            this.labelPlayerFirstName = new System.Windows.Forms.Label();
            this.labelPlayerSecondName = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(174, 112);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(123, 26);
            this.btnStart.TabIndex = 2;
            this.btnStart.Text = "Start Battle";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // textBoxPlayerFirst
            // 
            this.textBoxPlayerFirst.Location = new System.Drawing.Point(53, 86);
            this.textBoxPlayerFirst.Name = "textBoxPlayerFirst";
            this.textBoxPlayerFirst.Size = new System.Drawing.Size(163, 20);
            this.textBoxPlayerFirst.TabIndex = 3;
            this.textBoxPlayerFirst.Text = "Enosha";
            // 
            // textBoxPlayerSecond
            // 
            this.textBoxPlayerSecond.Location = new System.Drawing.Point(265, 86);
            this.textBoxPlayerSecond.Name = "textBoxPlayerSecond";
            this.textBoxPlayerSecond.Size = new System.Drawing.Size(163, 20);
            this.textBoxPlayerSecond.TabIndex = 4;
            this.textBoxPlayerSecond.Text = "Riley";
            // 
            // labelPlayerFirstName
            // 
            this.labelPlayerFirstName.AutoSize = true;
            this.labelPlayerFirstName.Location = new System.Drawing.Point(93, 70);
            this.labelPlayerFirstName.Name = "labelPlayerFirstName";
            this.labelPlayerFirstName.Size = new System.Drawing.Size(89, 13);
            this.labelPlayerFirstName.TabIndex = 5;
            this.labelPlayerFirstName.Text = "First Player Name";
            // 
            // labelPlayerSecondName
            // 
            this.labelPlayerSecondName.AutoSize = true;
            this.labelPlayerSecondName.Location = new System.Drawing.Point(311, 70);
            this.labelPlayerSecondName.Name = "labelPlayerSecondName";
            this.labelPlayerSecondName.Size = new System.Drawing.Size(89, 13);
            this.labelPlayerSecondName.TabIndex = 6;
            this.labelPlayerSecondName.Text = "First Player Name";
            // 
            // formInputPlayer
            // 
            this.AcceptButton = this.btnStart;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(506, 240);
            this.Controls.Add(this.labelPlayerSecondName);
            this.Controls.Add(this.labelPlayerFirstName);
            this.Controls.Add(this.textBoxPlayerSecond);
            this.Controls.Add(this.textBoxPlayerFirst);
            this.Controls.Add(this.btnStart);
            this.Name = "formInputPlayer";
            this.Text = "formInputPlayer";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.TextBox textBoxPlayerFirst;
        private System.Windows.Forms.TextBox textBoxPlayerSecond;
        private System.Windows.Forms.Label labelPlayerFirstName;
        private System.Windows.Forms.Label labelPlayerSecondName;
    }
}