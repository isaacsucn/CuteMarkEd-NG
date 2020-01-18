/*
 * Copyright 2013 Christian Loose <christian.loose@hamburg.de>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  * The names of its contributors may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include "fontawesomeiconengineplugin.h"

#include "fontawesomeiconengine.h"

FontAwesomeIconEnginePlugin::FontAwesomeIconEnginePlugin(QObject *parent) :
    QIconEnginePlugin(parent)
{
}

#if QT_VERSION < 0x050000
QStringList FontAwesomeIconEnginePlugin::keys() const
{
    QStringList keys(QLatin1String("fontawesome"));
    return keys;
}
#endif // QT_VERSION < 0x050000

QIconEngine *FontAwesomeIconEnginePlugin::create(const QString &filename)
{
    FontAwesomeIconEngine *engine = new FontAwesomeIconEngine;
    if (!filename.isNull()) {
        int lastPoint = filename.lastIndexOf(QLatin1String("."));
        engine->setIconName(filename.left(lastPoint));
    }
    return engine;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(fontawesomeicon, FontAwesomeIconEnginePlugin)
#endif // QT_VERSION < 0x050000
