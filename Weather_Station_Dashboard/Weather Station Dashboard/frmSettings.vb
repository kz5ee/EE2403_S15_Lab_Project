Public Class frmSettings

    Private Sub frmSettings_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        If My.Settings.Temp = "°F" Then                         'Load saved temperature unit setting
            radFahrenheit.Checked = True
        Else
            radCelsius.Checked = True
        End If

        cboPressure.SelectedItem = My.Settings.Press            'Load saved pressure unit setting

        txtUpdateInterval.Text = My.Settings.Period.ToString    'Load saved update interval setting
        cboTimeUnits.SelectedItem = My.Settings.TUnits          'Load saved time unit setting
    End Sub


    Private Sub btnSaveSettings_Click(sender As Object, e As EventArgs) Handles btnSaveSettings.Click

        Dim result = MessageBox.Show("Save settings and close window?", "Confirm Submission", MessageBoxButtons.YesNoCancel)

        If result = Windows.Forms.DialogResult.Yes Then                 'Save temperature units setting
            If radFahrenheit.Checked = True Then
                My.Settings.Temp = "°F"
            Else
                My.Settings.Temp = "°C"
            End If

            My.Settings.Press = cboPressure.SelectedItem.ToString       'Save pressure units setting

            My.Settings.Period = CInt(txtUpdateInterval.Text)           'Save update interval setting
            My.Settings.TUnits = cboTimeUnits.SelectedItem.ToString     'Save time units setting

            Me.Close()
            If result = Windows.Forms.DialogResult.No Then
                Me.Close()
            End If
        Else
        End If



    End Sub
End Class