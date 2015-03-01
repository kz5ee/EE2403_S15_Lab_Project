Public Class frmMain

    Public Shared TempUnits As String = My.Settings.Temp
    Public Shared PressUnits As String = My.Settings.Press
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
            Case "s"
                UpdateInterval = Period * 1000
            Case "min"
                UpdateInterval = (Period * 60) * 1000
            Case "hr"
                UpdateInterval = (Period * 3600) * 1000
        End Select

        tmrUpdateData.Interval = UpdateInterval



    End Sub
End Class
