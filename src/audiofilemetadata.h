#pragma once

#include <nap/core.h>

namespace nap
{
    /**
     * AudioFileMetadata is a class that reads metadata from audio files.
     * It uses TagLib to read the metadata and provides methods to access
     * artist, album, track title, duration, release date, key, and label.
     */
    class NAPAPI AudioFileMetadata final
    {
        RTTI_ENABLE()
    public:
        /**
         * Opens the audio file at the given filepath and reads its metadata.
         * @param filepath the path to the audio file
         */
        AudioFileMetadata(const std::string& filepath);
        ~AudioFileMetadata();

        /**
         * Returns true if the metadata is valid.
         * @return true if the metadata is valid, false otherwise
         */
        bool isValid() const;

        /**
         * Retrieves the artist name from the metadata.
         * @param outArtist the output string to store the artist name
         * @return true if the artist name was retrieved successfully, false otherwise
         */
        bool getArtist(std::string& outArtist) const;

        /**
         * Retrieves the album name from the metadata.
         * @param outAlbum the output string to store the album name
         * @return true if the album name was retrieved successfully, false otherwise
         */
        bool getAlbum(std::string& outAlbum) const;

        /**
         * Retrieves the track title from the metadata.
         * @param outTrackTitle the output string to store the track title
         * @return true if the track title was retrieved successfully, false otherwise
         */
        bool getTrackTitle(std::string& outTrackTitle) const;

        /**
         * Retrieves the duration of the audio file in seconds.
         * @param outDuration the output variable to store the duration
         * @return true if the duration was retrieved successfully, false otherwise
         */
        bool getDuration(double& outDuration) const;

        /**
         * Retrieves the release date from the metadata.
         * @param outDate the output string to store the release date
         * @return true if the release date was retrieved successfully, false otherwise
         */
        bool getDate(std::string& outDate) const;

        /**
         * Retrieves the key from the metadata.
         * @param outKey the output string to store the key
         * @return true if the key was retrieved successfully, false otherwise
         */
        bool getKey(std::string& outKey) const;

        /**
         * Retrieves the label from the metadata.
         * @param outLabel the output string to store the label
         * @return true if the label was retrieved successfully, false otherwise
         */
        bool getLabel(std::string& outLabel) const;

        /**
         * Retrieves the BPM (Beats Per Minute) from the metadata.
         * @param outBPM the output float to store the BPM
         * @return true if the BPM was retrieved successfully, false otherwise
         */
        bool getBPM(float &outBPM) const;
    private:
        // Impl defined in cpp
        class Impl;
        std::unique_ptr<Impl> mImpl;
    };
}