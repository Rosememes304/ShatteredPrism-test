#include "AuthlibInjector.h"

#include "minecraft/auth/steps/AuthlibInjectorMetadataStep.h"
#include "minecraft/auth/steps/GetSkinStep.h"
#include "minecraft/auth/steps/MinecraftProfileStepMojang.h"
#include "minecraft/auth/steps/YggdrasilStep.h"

AuthlibInjectorRefresh::AuthlibInjectorRefresh(AccountData* data, QObject* parent) : AuthFlow(data, parent)
{
    m_steps.append(makeShared<YggdrasilStep>(m_data, QString()));
    m_steps.append(makeShared<MinecraftProfileStepMojang>(m_data));
    m_steps.append(makeShared<AuthlibInjectorMetadataStep>(m_data));
    m_steps.append(makeShared<GetSkinStep>(m_data));
}

AuthlibInjectorLogin::AuthlibInjectorLogin(AccountData* data, QString password, QObject* parent)
    : AuthFlow(data, parent), m_password(password)
{
    m_steps.append(makeShared<YggdrasilStep>(m_data, m_password));
    m_steps.append(makeShared<MinecraftProfileStepMojang>(m_data));
    m_steps.append(makeShared<AuthlibInjectorMetadataStep>(m_data));
    m_steps.append(makeShared<GetSkinStep>(m_data));
}
