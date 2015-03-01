Public Class frmMain

    Private Sub frmMain_KeyDown(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyEventArgs) Handles MyBase.KeyDown
        If e.KeyCode = Keys.F12 Then
            'MessageBox.Show("F12 has been pressed", "Keypress Handled")
            frmSettings.Show()
        End If
    End Sub

    Private Sub UpdateData()

    End Sub

    Private Sub tmrUpdateData_Tick(sender As Object, e As EventArgs) Handles tmrUpdateData.Tick
        UpdateData()
    End Sub
End Class
