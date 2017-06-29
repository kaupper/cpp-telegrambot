namespace telegram
{
    template <typename T, typename = typename std::enable_if<std::is_base_of<CommandSet, T>::value>::type>
    T & TelegramBot::RegisterCommandSet()
    {
        commandSets.push_back(new T(this));
        T *tmp = (T *) commandSets.back();
        tmp->Setup();
        return (T &) * tmp;
    }

    template <typename T, typename = typename std::enable_if<std::is_base_of<Command, T>::value>::type>
    T & TelegramBot::RegisterCommand(const std::string &name)
    {
        return defaultCommandSet.RegisterCommand<T>(this, name);
    }

    template <typename T, typename = typename std::enable_if<std::is_base_of<GeneralCallback, T>::value>::type>
    T & TelegramBot::RegisterGeneralCallback()
    {
        generalCallbacks.push_back(new T(*this));
        return (T &) * (generalCallbacks.back());
    }
}