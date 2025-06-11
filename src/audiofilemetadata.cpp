#include "audiofilemetadata.h"

#include <tag.h>
#include <fileref.h>
#include <tpropertymap.h>

#include "nap/logger.h"

RTTI_BEGIN_CLASS_NO_DEFAULT_CONSTRUCTOR(nap::AudioFileMetadata)
    RTTI_CONSTRUCTOR(const std::string&)
RTTI_END_CLASS

namespace nap
{
    static std::vector<std::string> release_date_names = {
        "RELEASE_TIME", "Release Date", "ORIGINAL_RELEASE_DATE", "ORIGINALDATE", "ORIGINAL_RELEASE_DATE",
        "ORIGINAL DATE", "ORIGINAL DATE", "RELEASE DATE", "RELEASE_DATE", "DATE"
    };

    static std::vector<std::string> key_names = {
        "KEY", "ORIGINAL_KEY", "ORIGINAL KEY", "INITIALKEY", "INITIAL_KEY"
    };

    class AudioFileMetadata::Impl
    {
    public:
        Impl(const std::string& filepath)
            : mFileRef(filepath.c_str())
        {}

        bool isValid() const
        {
            return !mFileRef.isNull();
        }

        TagLib::FileRef mFileRef; ///< Reference to the file
    };


    AudioFileMetadata::AudioFileMetadata(const std::string &filepath) : mImpl(std::make_unique<Impl>(filepath))
    { }


    AudioFileMetadata::~AudioFileMetadata()
    {
    }


    bool AudioFileMetadata::isValid() const
    {
        return mImpl->isValid();
    }


    bool AudioFileMetadata::getArtist(std::string& outArtist) const
    {
        if (!isValid())
            return false;

        outArtist = mImpl->mFileRef.tag()->artist().toCString();
        return true;
    }


    bool AudioFileMetadata::getAlbum(std::string& outAlbum) const
    {
        if (!isValid())
            return false;

        outAlbum = mImpl->mFileRef.tag()->album().toCString();
        return true;
    }


    bool AudioFileMetadata::getTrackTitle(std::string& outTrackTitle) const
    {
        if (!isValid())
            return false;

        outTrackTitle = mImpl->mFileRef.tag()->title().toCString();
        return true;
    }


    bool AudioFileMetadata::getDuration(double &outDuration) const
    {
        if (!isValid())
            return false;

        auto audioProperties = mImpl->mFileRef.audioProperties();
        if (!audioProperties)
            return false;

        outDuration = audioProperties->lengthInSeconds();
        return true;
    }


    bool AudioFileMetadata::getDate(std::string &outDate) const
    {
        if (!isValid())
            return false;

        TagLib::PropertyMap props = mImpl->mFileRef.tag()->properties();
        for (const auto& name : release_date_names)
        {
            if (props.contains(name))
            {
                outDate = props[name].toString().toCString();
                return true;
            }
        }

        return false;
    }


    bool AudioFileMetadata::getKey(std::string &outKey) const
    {
        if (!isValid())
            return false;

        TagLib::PropertyMap props = mImpl->mFileRef.tag()->properties();
        for (const auto& name : key_names)
        {
            if (props.contains(name))
            {
                outKey = props[name].toString().toCString();
                return true;
            }
        }

        return false;
    }


    bool AudioFileMetadata::getLabel(std::string &outLabel) const
    {
        if (!isValid())
            return false;

        TagLib::PropertyMap props = mImpl->mFileRef.tag()->properties();
        if (props.contains("LABEL"))
        {
            outLabel = props["LABEL"].toString().toCString();
            return true;
        }

        return false;
    }

    bool AudioFileMetadata::getBPM(float &outBPM) const
    {
        if (!isValid())
            return false;

        TagLib::PropertyMap props = mImpl->mFileRef.tag()->properties();
        if (props.contains("BPM"))
        {
            try
            {
                const float bpm = std::stof(props["BPM"].toString().toCString());
                outBPM = bpm;
            }catch (...)
            {
                nap::Logger::error("Failed to parse BPM from metadata for file: %s", mImpl->mFileRef.file());
            }

            return true;
        }

        return false;
    }
}