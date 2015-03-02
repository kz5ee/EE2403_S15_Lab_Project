Imports System
Imports System.IO.Ports

Public Class frmMain

    Public Shared TempUnits As String = My.Settings.Temp
    Public Shared PressUnits As String = My.Settings.Press

    Dim WithEvents ComPort As SerialPort = New System.IO.Ports.SerialPort("COM1", _
                                                                          9600, _
                                                                          Parity.None, _
                                                                          8, _
                                                                          StopBits.One)

    Private Sub frmMain_KeyDown(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyEventArgs) Handles MyBase.KeyDown
        If e.KeyCode = Keys.F3 Then
            'MessageBox.Show("F12 has been pressed", "Keypress Handled")
            frmSettings.Show()
        End If

        If e.KeyCode = Keys.F12 Then
            MessageBox.Show("F12 has been pressed", "Keypress Handled")
            'frmSettings.Show()
        End If

    End Sub

    Private Sub UpdateData()

    End Sub

    Private Sub tmrUpdateData_Tick(sender As Object, e As EventArgs) Handles tmrUpdateData.Tick
        UpdateData()
    End Sub

    Private Sub frmMain_Load(sender As Object, e As EventArgs) Handles MyBase.Load

        Dim UpdateInterval, Period As Integer
        Dim TimeUnits As String = My.Settings.TUnits.ToString

        Period = CInt(My.Settings.Period)

        Select Case TimeUnits
            Case "ms"
                UpdateInterval = Period
            Case "s"
                UpdateInterval = Period * 1000
            Case "min"
                UpdateInterval = (Period * 60) * 1000
            Case "hr"
                UpdateInterval = (Period * 3600) * 1000
        End Select

        tmrUpdateData.Interval = UpdateInterval

        GetSerialPortNames()
        tmrGetSerialPorts.Enabled = True

    End Sub

    Sub GetSerialPortNames()
        ' Show all available COM ports. 

        ' Get a list of serial port names. 
        Dim ports As String() = SerialPort.GetPortNames()

        ' Display each port name to the console. 
        Dim port As String
        If ports.Count <> CInt(cboSerialPorts.Items.Count) Then
            For Each port In ports
                cboSerialPorts.Items.Add(port)
            Next port

            If cboSerialPorts.Text = "" Then
                cboSerialPorts.Text = port.ToString
                cboSerialPorts.SelectedItem = port
            End If

        End If

    End Sub

    Private Sub tmrGetSerialPorts_Tick(sender As Object, e As EventArgs) Handles tmrGetSerialPorts.Tick
        GetSerialPortNames()
    End Sub

    Private Sub btnOpenPort_Click(sender As Object, e As EventArgs) Handles btnOpenPort.Click

        ComPort.PortName = cboSerialPorts.SelectedItem
        ComPort.BaudRate = cboBaudRate.SelectedItem

        If Not ComPort.IsOpen Then

            ComPort.Open()
            cboBaudRate.Enabled = False
            cboSerialPorts.Enabled = False
            btnOpenPort.Enabled = False
            btnClosePort.Enabled = True
        End If

    End Sub

    Private Sub btnClosePort_Click(sender As Object, e As EventArgs) Handles btnClosePort.Click
        If ComPort.IsOpen Then
            ComPort.Close()
            ComPort.Dispose()
            cboBaudRate.Enabled = True
            cboSerialPorts.Enabled = True
            btnOpenPort.Enabled = True
            btnClosePort.Enabled = False
        End If
    End Sub
End Class
