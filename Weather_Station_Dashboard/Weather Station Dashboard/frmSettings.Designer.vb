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
        Me.lblPressure = New System.Windows.Forms.Label()
        Me.txtUpdateInterval = New System.Windows.Forms.TextBox()
        Me.lblUpdate = New System.Windows.Forms.Label()
        Me.cboTimeUnits = New System.Windows.Forms.ComboBox()
        Me.grpTemperature = New System.Windows.Forms.GroupBox()
        Me.grpSpeed = New System.Windows.Forms.GroupBox()
        Me.radMPH = New System.Windows.Forms.RadioButton()
        Me.radKPH = New System.Windows.Forms.RadioButton()
        Me.radKnot = New System.Windows.Forms.RadioButton()
        Me.grpTemperature.SuspendLayout()
        Me.grpSpeed.SuspendLayout()
        Me.SuspendLayout()
        '
        'btnSaveSettings
        '
        Me.btnSaveSettings.Location = New System.Drawing.Point(322, 166)
        Me.btnSaveSettings.Name = "btnSaveSettings"
        Me.btnSaveSettings.Size = New System.Drawing.Size(82, 23)
        Me.btnSaveSettings.TabIndex = 1
        Me.btnSaveSettings.Text = "Save Settings"
        Me.btnSaveSettings.UseVisualStyleBackColor = True
        '
        'radFahrenheit
        '
        Me.radFahrenheit.AutoSize = True
        Me.radFahrenheit.Location = New System.Drawing.Point(6, 19)
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
        Me.radCelsius.Location = New System.Drawing.Point(87, 19)
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
        'grpTemperature
        '
        Me.grpTemperature.Controls.Add(Me.radFahrenheit)
        Me.grpTemperature.Controls.Add(Me.radCelsius)
        Me.grpTemperature.Location = New System.Drawing.Point(12, 36)
        Me.grpTemperature.Name = "grpTemperature"
        Me.grpTemperature.Size = New System.Drawing.Size(200, 37)
        Me.grpTemperature.TabIndex = 10
        Me.grpTemperature.TabStop = False
        Me.grpTemperature.Text = "Temperature"
        '
        'grpSpeed
        '
        Me.grpSpeed.Controls.Add(Me.radKnot)
        Me.grpSpeed.Controls.Add(Me.radMPH)
        Me.grpSpeed.Controls.Add(Me.radKPH)
        Me.grpSpeed.Location = New System.Drawing.Point(234, 123)
        Me.grpSpeed.Name = "grpSpeed"
        Me.grpSpeed.Size = New System.Drawing.Size(170, 37)
        Me.grpSpeed.TabIndex = 11
        Me.grpSpeed.TabStop = False
        Me.grpSpeed.Text = "Speed"
        '
        'radMPH
        '
        Me.radMPH.AutoSize = True
        Me.radMPH.Location = New System.Drawing.Point(6, 14)
        Me.radMPH.Name = "radMPH"
        Me.radMPH.Size = New System.Drawing.Size(49, 17)
        Me.radMPH.TabIndex = 2
        Me.radMPH.TabStop = True
        Me.radMPH.Text = "MPH"
        Me.radMPH.UseVisualStyleBackColor = True
        '
        'radKPH
        '
        Me.radKPH.AutoSize = True
        Me.radKPH.Location = New System.Drawing.Point(61, 14)
        Me.radKPH.Name = "radKPH"
        Me.radKPH.Size = New System.Drawing.Size(47, 17)
        Me.radKPH.TabIndex = 3
        Me.radKPH.TabStop = True
        Me.radKPH.Text = "KPH"
        Me.radKPH.UseVisualStyleBackColor = True
        '
        'radKnot
        '
        Me.radKnot.AutoSize = True
        Me.radKnot.Location = New System.Drawing.Point(114, 14)
        Me.radKnot.Name = "radKnot"
        Me.radKnot.Size = New System.Drawing.Size(47, 17)
        Me.radKnot.TabIndex = 4
        Me.radKnot.TabStop = True
        Me.radKnot.Text = "Knot"
        Me.radKnot.UseVisualStyleBackColor = True
        '
        'frmSettings
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(422, 198)
        Me.Controls.Add(Me.grpSpeed)
        Me.Controls.Add(Me.grpTemperature)
        Me.Controls.Add(Me.cboTimeUnits)
        Me.Controls.Add(Me.lblUpdate)
        Me.Controls.Add(Me.txtUpdateInterval)
        Me.Controls.Add(Me.lblPressure)
        Me.Controls.Add(Me.cboPressure)
        Me.Controls.Add(Me.btnSaveSettings)
        Me.Name = "frmSettings"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "Display Settings"
        Me.grpTemperature.ResumeLayout(False)
        Me.grpTemperature.PerformLayout()
        Me.grpSpeed.ResumeLayout(False)
        Me.grpSpeed.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents btnSaveSettings As System.Windows.Forms.Button
    Friend WithEvents radFahrenheit As System.Windows.Forms.RadioButton
    Friend WithEvents radCelsius As System.Windows.Forms.RadioButton
    Friend WithEvents cboPressure As System.Windows.Forms.ComboBox
    Friend WithEvents lblPressure As System.Windows.Forms.Label
    Friend WithEvents txtUpdateInterval As System.Windows.Forms.TextBox
    Friend WithEvents lblUpdate As System.Windows.Forms.Label
    Friend WithEvents cboTimeUnits As System.Windows.Forms.ComboBox
    Friend WithEvents grpTemperature As System.Windows.Forms.GroupBox
    Friend WithEvents grpSpeed As System.Windows.Forms.GroupBox
    Friend WithEvents radKnot As System.Windows.Forms.RadioButton
    Friend WithEvents radMPH As System.Windows.Forms.RadioButton
    Friend WithEvents radKPH As System.Windows.Forms.RadioButton
End Class
