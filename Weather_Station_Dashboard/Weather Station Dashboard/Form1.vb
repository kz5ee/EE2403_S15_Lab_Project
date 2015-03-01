Public Class Form1

    Private Sub frmMain_KeyDown(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyEventArgs) Handles MyBase.KeyDown
        If e.KeyCode = Keys.F12 Then
            MessageBox.Show("F12 has been pressed", "Keypress Handled")
        End If
    End Sub

End Class
