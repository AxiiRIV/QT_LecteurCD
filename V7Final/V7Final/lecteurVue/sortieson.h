#ifndef SORTIESON_H
#define SORTIESON_H

#include <QAudioOutput>
#include <QMediaDevices>
#include <QObject>

class SortieSon : public QAudioOutput
{
    Q_OBJECT
public:
    SortieSon(QObject *parent = nullptr);
    ~SortieSon();

    /* ------------
     * Actions susceptibles d'êtres déclenchées sur la sortie son conformément au cahier des charges.
     * --------------------------------------------------*/

public slots:
    void setVolume(float pVolume);
    // modifie le volume de la sortie son
    void desactiverSon();
    // coupe le son
    void activerSon();
    // remet le son, au niveau de volume défini par setVolume
};


#endif // SORTIESON_H
