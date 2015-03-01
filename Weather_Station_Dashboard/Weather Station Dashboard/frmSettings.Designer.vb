<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmSettings
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.btnSaveSettings = New System.Windows.Forms.Button()
        Me.radFahrenheit = New System.Windows.Forms.RadioButton()
        Me.radCelsius = New System.Windows.Forms.RadioButton()
        Me.cboPressure = New System.Windows.Forms.ComboBox()
        Me.lblTemp = New System.Windows.Forms.Label()
        Me.lblPressure = New System.Windows.Forms.Label()
        Me.txtUpdateInterval = New System.Windows.Forms.TextBox()
        Me.lblUpdate = New System.Windows.Forms.Label()
        Me.cboTimeUnits = New System.Windows.Forms.ComboBox()
        Me.SuspendLayout()
        '
        'btnSaveSettings
        '
        Me.btnSaveSettings.Location = New System.Drawing.Point(234, 137)
        Me.btnSaveSettings.Name = "btnSaveSettings"
        Me.btnSaveSettings.Size = New System.Drawing.Size(82, 23)
        Me.btnSaveSettings.TabIndex = 1
        Me.btnSaveSettings.Text = "Save Settings"
        Me.btnSaveSettings.UseVisualStyleBackColor = True
        '
        'radFahrenheit
        '
        Me.radFahrenheit.AutoSize = True
        Me.radFahrenheit.Location = New System.Drawing.Point(35, 55)
        Me.radFahrenheit.Name = "radFahrenheit"
        Me.radFahrenheit.Size = New System.Drawing.Size(75, 17)
        Me.radFahrenheit.TabIndex = 2
        Me.radFahrenheit.TabStop = True
        Me.radFahrenheit.Text = "Fahrenheit"
        Me.radFahrenheit.UseVisualStyleBackColor = True
        '
        'radCelsius
        '
        Me.radCelsius.AutoSize = True
        Me.radCelsius.Location = New System.Drawing.Point(116, 55)
        Me.radCelsius.Name = "radCelsius"
        Me.radCelsius.Size = New System.Drawing.Size(58, 17)
        Me.radCelsius.TabIndex = 3
        Me.radCelsius.TabStop = True
        Me.radCelsius.Text = "Celsius"
        Me.radCelsius.UseVisualStyleBackColor = True
        '
        'cboPressure
        '
        Me.cboPressure.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cboPressure.FormattingEnabled = True
        Me.cboPressure.Items.AddRange(New Object() {"in. Hg", "mmHg", "hPa", "kPa", "mbar", "bar", "psi"})
        Me.cboPressure.Location = New System.Drawing.Point(234, 55)
        Me.cboPressure.Name = "cboPressure"
        Me.cboPressure.Size = New System.Drawing.Size(121, 21)
        Me.cboPressure.TabIndex = 4
        '
        'lblTemp
        '
        Me.lblTemp.AutoSize = True
        Me.lblTemp.Location = New System.Drawing.Point(35, 36)
        Me.lblTemp.Name = "lblTemp"
        Me.lblTemp.Size = New System.Drawing.Size(67, 13)
        Me.lblTemp.TabIndex = 5
        Me.lblTemp.Text = "Temperature"
        '
        'lblPressure
        '
        Me.lblPressure.AutoSize = True
        Me.lblPressure.Location = New System.Drawing.Point(231, 36)
        Me.lblPressure.Name = "lblPressure"
        Me.lblPressure.Size = New System.Drawing.Size(48, 13)
        Me.lblPressure.TabIndex = 6
        Me.lblPressure.Text = "Pressure"
        '
        'txtUpdateInterval
        '
        Me.txtUpdateInterval.Location = New System.Drawing.Point(38, 140)
        Me.txtUpdateInterval.Name = "txtUpdateInterval"
        Me.txtUpdateInterval.Size = New System.Drawing.Size(100, 20)
        Me.txtUpdateInterval.TabIndex = 7
        '
        'lblUpdate
        '
        Me.lblUpdate.AutoSize = True
        Me.lblUpdate.Location = New System.Drawing.Point(35, 124)
        Me.lblUpdate.Name = "lblUpdate"
        Me.lblUpdate.Size = New System.Drawing.Size(80, 13)
        Me.lblUpdate.TabIndex = 8
        Me.lblUpdate.Text = "Update Interval"
        '
        'cboTimeUnits
        '
        Me.cboTimeUnits.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cboTimeUnits.FormattingEnabled = True
        Me.cboTimeUnits.Items.AddRange(New Object() {"ms", "s", "min", "hr"})
        Me.cboTimeUnits.Location = New System.Drawing.Point(144, 139)
        Me.cboTimeUnits.Name = "cboTimeUnits"
        Me.cboTimeUnits.Size = New System.Drawing.Size(49, 21)
        Me.cboTimeUnits.TabIndex = 9
        '
        'frmSettings
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(462, 223)
        Me.Controls.Add(Me.cboTimeUnits)
        Me.Controls.Add(Me.lblUpdate)
        Me.Controls.Add(Me.txtUpdateInterval)
        Me.Controls.Add(Me.lblPressure)
        Me.Controls.Add(Me.lblTemp)
        Me.Controls.Add(Me.cboPressure)
        Me.Controls.Add(Me.radCelsius)
        Me.Controls.Add(Me.radFahrenheit)
        Me.Controls.Add(Me.btnSaveSettings)
        Me.Name = "frmSettings"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "Display Settings"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents btnSaveSettings As System.Windows.Forms.Button
    Friend WithEvents radFahrenheit As System.Windows.Forms.RadioButton
    Friend WithEvents radCelsius As System.Windows.Forms.RadioButton
    Friend WithEvents cboPressure As System.Windows.Forms.ComboBox
    Friend WithEvents lblTemp As System.Windows.Forms.Label
    Friend WithEvents lblPressure As System.Windows.Forms.Label
    Friend WithEvents txtUpdateInterval As System.Windows.Forms.TextBox
    Friend WithEvents lblUpdate As System.Windows.Forms.Label
    Friend WithEvents cboTimeUnits As System.Windows.Forms.ComboBox
End Class
