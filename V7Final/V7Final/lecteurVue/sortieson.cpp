#include "sortieson.h"
#include <QDebug>

SortieSon::SortieSon(QObject *parent)
    : QAudioOutput{parent}
{
    qDebug() << "SortieSon::Construction" << Qt::endl;

}

SortieSon::~SortieSon()
{ qDebug() << "SortieSon::Destruction de la SortieSon " << Qt::endl; }


void SortieSon::setVolume(float pVolume)
{
    qDebug() << "SortieSon::set Volume" << Qt::endl;
    QAudioOutput::setVolume(pVolume);
}

void SortieSon::desactiverSon()
{
    qDebug() << "SortieSon::désactiver Volume" << Qt::endl;
    QAudioOutput::setMuted(true);
}

void SortieSon::activerSon()
{
    qDebug() << "SortieSon::activer Volume" << Qt::endl;
    QAudioOutput::setMuted(false);
}


/* Remarque concernabt le CONSTRUCTEUR
 * La construction par défaut associe la sortieSon au périphérique de sortie par défaut de l'ordinateur.
    sinon, = si on veut choisir le périphérique, regarder QMediaClasses device

     * const QList<QAudioDevice> audioDevices = QMediaDevices::audioOutputs();
    for (const QAudioDevice &device : audioDevices)
    {
        out << "ID: " << device.id() << Qt::endl;
        out << "Description: " << device.description() << Qt::endl;
        out << "Is default: " << (device.isDefault() ? "Yes" : "No") << Qt::endl;
    }

    et manière d'en choisr un autre
    #include <QMediaDevices>
    #include <QAudioOutput>

    QList<QAudioDevice> devices = QMediaDevices::audioOutputs();
    for (const QAudioDevice &device : devices) {
        qDebug() << "Nom:" << device.description();
    }

    // Sélection d'un périphérique spécifique (par exemple, le 2e)
    QAudioDevice chosenDevice = devices.at(1);
    QAudioOutput *output = new QAudioOutput(chosenDevice);
     */
