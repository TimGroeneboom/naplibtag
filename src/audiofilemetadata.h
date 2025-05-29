#pragma once

#include <nap/core.h>

namespace nap
{
    class NAPAPI AudioFileMetadata
    {
        RTTI_ENABLE()
    public:
        AudioFileMetadata(const std::string& filepath);
        ~AudioFileMetadata();

        bool isValid() const;

        bool getArtist(std::string& outArtist) const;

        bool getAlbum(std::string& outAlbum) const;

        bool getTrackTitle(std::string& outTrackTitle) const;

        bool getDuration(double& outDuration) const;

        bool getDate(std::string& outDate) const;

        bool getKey(std::string& outKey) const;

        bool getLabel(std::string& outLabel) const;
    private:
        class Impl;
        std::unique_ptr<Impl> mImpl;
    };
}