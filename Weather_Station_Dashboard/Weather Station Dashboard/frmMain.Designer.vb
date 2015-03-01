<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmMain
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
        Me.components = New System.ComponentModel.Container()
        Me.tmrUpdateData = New System.Windows.Forms.Timer(Me.components)
        Me.lblTemp = New System.Windows.Forms.Label()
        Me.lblTempData = New System.Windows.Forms.Label()
        Me.lblPressData = New System.Windows.Forms.Label()
        Me.lblPress = New System.Windows.Forms.Label()
        Me.lblWindSpeedData = New System.Windows.Forms.Label()
        Me.lblWindSpeed = New System.Windows.Forms.Label()
        Me.lblGPSLat = New System.Windows.Forms.Label()
        Me.lblGPS = New System.Windows.Forms.Label()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.lblMaidenhead = New System.Windows.Forms.Label()
        Me.lblGPSLon = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'tmrUpdateData
        '
        Me.tmrUpdateData.Enabled = True
        Me.tmrUpdateData.Interval = 1000
        '
        'lblTemp
        '
        Me.lblTemp.AutoSize = True
        Me.lblTemp.Font = New System.Drawing.Font("Microsoft Sans Serif", 24.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblTemp.Location = New System.Drawing.Point(65, 88)
        Me.lblTemp.Name = "lblTemp"
        Me.lblTemp.Size = New System.Drawing.Size(200, 37)
        Me.lblTemp.TabIndex = 0
        Me.lblTemp.Text = "Temperature"
        '
        'lblTempData
        '
        Me.lblTempData.AutoSize = True
        Me.lblTempData.Font = New System.Drawing.Font("Microsoft Sans Serif", 27.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblTempData.Location = New System.Drawing.Point(98, 125)
        Me.lblTempData.Name = "lblTempData"
        Me.lblTempData.Size = New System.Drawing.Size(113, 42)
        Me.lblTempData.TabIndex = 1
        Me.lblTempData.Text = "76 °F"
        '
        'lblPressData
        '
        Me.lblPressData.AutoSize = True
        Me.lblPressData.Font = New System.Drawing.Font("Microsoft Sans Serif", 27.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblPressData.Location = New System.Drawing.Point(281, 125)
        Me.lblPressData.Name = "lblPressData"
        Me.lblPressData.Size = New System.Drawing.Size(231, 42)
        Me.lblPressData.TabIndex = 3
        Me.lblPressData.Text = "29.92 in. Hg"
        '
        'lblPress
        '
        Me.lblPress.AutoSize = True
        Me.lblPress.Font = New System.Drawing.Font("Microsoft Sans Serif", 24.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblPress.Location = New System.Drawing.Point(323, 88)
        Me.lblPress.Name = "lblPress"
        Me.lblPress.Size = New System.Drawing.Size(144, 37)
        Me.lblPress.TabIndex = 2
        Me.lblPress.Text = "Pressure"
        '
        'lblWindSpeedData
        '
        Me.lblWindSpeedData.AutoSize = True
        Me.lblWindSpeedData.Font = New System.Drawing.Font("Microsoft Sans Serif", 27.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblWindSpeedData.Location = New System.Drawing.Point(564, 125)
        Me.lblWindSpeedData.Name = "lblWindSpeedData"
        Me.lblWindSpeedData.Size = New System.Drawing.Size(159, 42)
        Me.lblWindSpeedData.TabIndex = 5
        Me.lblWindSpeedData.Text = "45 MPH"
        '
        'lblWindSpeed
        '
        Me.lblWindSpeed.AutoSize = True
        Me.lblWindSpeed.Font = New System.Drawing.Font("Microsoft Sans Serif", 24.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblWindSpeed.Location = New System.Drawing.Point(546, 88)
        Me.lblWindSpeed.Name = "lblWindSpeed"
        Me.lblWindSpeed.Size = New System.Drawing.Size(191, 37)
        Me.lblWindSpeed.TabIndex = 4
        Me.lblWindSpeed.Text = "Wind Speed"
        '
        'lblGPSLat
        '
        Me.lblGPSLat.AutoSize = True
        Me.lblGPSLat.Font = New System.Drawing.Font("Microsoft Sans Serif", 27.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblGPSLat.Location = New System.Drawing.Point(87, 336)
        Me.lblGPSLat.Name = "lblGPSLat"
        Me.lblGPSLat.Size = New System.Drawing.Size(257, 42)
        Me.lblGPSLat.TabIndex = 7
        Me.lblGPSLat.Text = "32° 43.937' N"
        '
        'lblGPS
        '
        Me.lblGPS.AutoSize = True
        Me.lblGPS.Font = New System.Drawing.Font("Microsoft Sans Serif", 24.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblGPS.Location = New System.Drawing.Point(98, 299)
        Me.lblGPS.Name = "lblGPS"
        Me.lblGPS.Size = New System.Drawing.Size(215, 37)
        Me.lblGPS.TabIndex = 6
        Me.lblGPS.Text = "GPS Location"
        '
        'Label9
        '
        Me.Label9.AutoSize = True
        Me.Label9.Font = New System.Drawing.Font("Microsoft Sans Serif", 27.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label9.Location = New System.Drawing.Point(512, 336)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(153, 42)
        Me.Label9.TabIndex = 8
        Me.Label9.Text = "EM12kr"
        '
        'lblMaidenhead
        '
        Me.lblMaidenhead.AutoSize = True
        Me.lblMaidenhead.Font = New System.Drawing.Font("Microsoft Sans Serif", 24.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblMaidenhead.Location = New System.Drawing.Point(492, 299)
        Me.lblMaidenhead.Name = "lblMaidenhead"
        Me.lblMaidenhead.Size = New System.Drawing.Size(192, 37)
        Me.lblMaidenhead.TabIndex = 9
        Me.lblMaidenhead.Text = "Maidenhead"
        '
        'lblGPSLon
        '
        Me.lblGPSLon.AutoSize = True
        Me.lblGPSLon.Font = New System.Drawing.Font("Microsoft Sans Serif", 27.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblGPSLon.Location = New System.Drawing.Point(87, 378)
        Me.lblGPSLon.Name = "lblGPSLon"
        Me.lblGPSLon.Size = New System.Drawing.Size(243, 42)
        Me.lblGPSLon.TabIndex = 10
        Me.lblGPSLon.Text = "97° 6.813' W"
        '
        'frmMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(851, 753)
        Me.Controls.Add(Me.lblGPSLon)
        Me.Controls.Add(Me.lblMaidenhead)
        Me.Controls.Add(Me.Label9)
        Me.Controls.Add(Me.lblGPSLat)
        Me.Controls.Add(Me.lblGPS)
        Me.Controls.Add(Me.lblWindSpeedData)
        Me.Controls.Add(Me.lblWindSpeed)
        Me.Controls.Add(Me.lblPressData)
        Me.Controls.Add(Me.lblPress)
        Me.Controls.Add(Me.lblTempData)
        Me.Controls.Add(Me.lblTemp)
        Me.Name = "frmMain"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "Weather Station Dashboard"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents tmrUpdateData As System.Windows.Forms.Timer
    Friend WithEvents lblTemp As System.Windows.Forms.Label
    Friend WithEvents lblTempData As System.Windows.Forms.Label
    Friend WithEvents lblPressData As System.Windows.Forms.Label
    Friend WithEvents lblPress As System.Windows.Forms.Label
    Friend WithEvents lblWindSpeedData As System.Windows.Forms.Label
    Friend WithEvents lblWindSpeed As System.Windows.Forms.Label
    Friend WithEvents lblGPSLat As System.Windows.Forms.Label
    Friend WithEvents lblGPS As System.Windows.Forms.Label
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents lblMaidenhead As System.Windows.Forms.Label
    Friend WithEvents lblGPSLon As System.Windows.Forms.Label

End Class
